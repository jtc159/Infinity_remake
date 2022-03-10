#pragma once

#include <vector>

//#ifdef IF_DEBUG
//#include <iostream>
//#endif // IF_DEBUG


namespace Infinity
{
	template<typename T> class IFEvent;
	template<typename T> class IFDelegate;


	template<typename RETURNTYPE, typename... ARGS>
	class IFDelegate<RETURNTYPE(ARGS...)>
	{
		using FP_WITH_POINTER = RETURNTYPE(*)(void*, ARGS...);
		using FP = RETURNTYPE(*)(ARGS...);
	public:
		IFDelegate() = default;
		static IFDelegate<RETURNTYPE(ARGS...)> CreateDelegate(void* p, FP_WITH_POINTER f)
		{
			IFDelegate<RETURNTYPE(ARGS...)> res;
			res.m_p = p;
			res.m_f = f;
			return res;
		}

		template<FP F>
		static RETURNTYPE FuncStub(void* p, ARGS... args) {
			return F(args...);
		}

		template<typename C, RETURNTYPE(C::* CF)(ARGS...)>
		static RETURNTYPE MethodStub(void* p, ARGS... args)
		{
			C* Cp = (C*)p;
			return (Cp->*CF)(args...);
		}

		template<FP F>
		static IFDelegate<RETURNTYPE(ARGS...)> CreateFromFunc()
		{
			IFDelegate<RETURNTYPE(ARGS...)> res;
			res.m_f = &FuncStub<F>;
			return res;
		}


		template<typename C, RETURNTYPE(C::* CF)(ARGS...)>
		static IFDelegate<RETURNTYPE(ARGS...)> CreateFromMethod(C* p)
		{
			IFDelegate<RETURNTYPE(ARGS...)> res;
			res.m_p = p;
			res.m_f = &MethodStub<C, CF>;
			return res;
		}


		RETURNTYPE operator()(ARGS... args) {
			return m_f(m_p, args...);
		}

		FP_WITH_POINTER m_f;
		void* m_p;
	};


	template<typename RETURNTYPE, typename... ARGS>
	class IFEvent<RETURNTYPE(ARGS...)>
	{
		using Handler = IFDelegate<RETURNTYPE(ARGS...)>;
	public:
		IFEvent() = default;
		IFEvent(Handler handler)
		{
			Add(handler);
		}

		void operator+=(Handler handler)
		{
			Add(handler);
		}

		void operator-=(Handler handler)
		{
			Remove(handler);
		}

		void operator()(ARGS... args)
		{
			for (Handler& handler : m_Handlers) {
				handler(args...);
			}
		}

	private:

		void Add(Handler handler)
		{
			m_Handlers.push_back(handler);
		}

		void Remove(Handler handler)
		{
			auto it = m_Handlers.find(handler);
			if (it != m_Handlers.end()) {
				m_Handlers.erase(handler);
			}
		}

		std::vector<Handler> m_Handlers;

	};

}
