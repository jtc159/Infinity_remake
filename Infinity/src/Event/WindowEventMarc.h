#pragma once

// Delegate
#define WINDOW_CLOSE_DELEGATE IFDelegate<void()>
#define WINDOW_RESIZE_DELEGATE IFDelegate<void(int, int)>

#define KEY_PRESS_DELEGATE IFDelegate<void(int)>
#define KEY_TYPE_DELEGATE IFDelegate<void(int)>
#define KEY_REPEAT_DELEGATE IFDelegate<void(int)>
#define KEY_RELEASE_DELEGATE IFDelegate<void(int)>

#define MOUSE_PRESS_DELEGATE IFDelegate<void(int)>
#define MOUSE_REPEAT_DELEGATE IFDelegate<void(int)>
#define MOUSE_RELEASE_DELEGATE IFDelegate<void(int)>

#define MOUSE_MOVE_DELEGATE IFDelegate<void(float, float)>
#define MOUSE_SCROLL_DELEGATE IFDelegate<void(float, float)>


// Event
#define WINDOW_CLOSE_EVENT IFEvent<void()>
#define WINDOW_RESIZE_EVENT IFEvent<void(int, int)>

#define KEY_PRESS_EVENT IFEvent<void(int)>
#define KEY_TYPE_EVENT IFEvent<void(int)>
#define KEY_REPEAT_EVENT IFEvent<void(int)>
#define KEY_RELEASE_EVENT IFEvent<void(int)>

#define MOUSE_PRESS_EVENT IFEvent<void(int)>
#define MOUSE_REPEAT_EVENT IFEvent<void(int)>
#define MOUSE_RELEASE_EVENT IFEvent<void(int)>

#define MOUSE_MOVE_EVENT IFEvent<void(float, float)>
#define MOUSE_SCROLL_EVENT IFEvent<void(float, float)>