#include <mvc.h>

int main(int argc, char* argv[]) {

#if IS_MSVC
	if (CONFIG_ENABLE_CONSOLE_TITLE) {
		SetConsoleTitle(CONFIG_CONSOLE_TITLE);
	}
#endif

	//Preprare for the cpu gets idle
	//Sleep(10000);
	int _app_ret_val = AppController(argc, argv);

	return _app_ret_val;
}