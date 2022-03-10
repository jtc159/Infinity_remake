#pragma once

extern Infinity::Application* Infinity::CreateApplication();

int main(int argc, char** argv) {
	Infinity::Log::Init();
	IF_ERROR("EntryPoint");
	Infinity::Application* app = Infinity::CreateApplication();
	app->Run();
	return 0;
}