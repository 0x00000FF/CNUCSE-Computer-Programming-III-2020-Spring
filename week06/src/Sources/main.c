#include <mvc.h>
#include <app/app_controller.h>

int main(int argc, char* argv[]) {

#if IS_MSVC
	if (CONFIG_ENABLE_CONSOLE_TITLE) {
		SetConsoleTitle(CONFIG_CONSOLE_TITLE);
	}
#endif

	AppController* controller = METHOD_STATIC(AppController, create, argc, argv);
	METHOD(AppController, controller, run);

	int _app_ret_val = METHOD(AppController, controller, get_return);
	return _app_ret_val;
}