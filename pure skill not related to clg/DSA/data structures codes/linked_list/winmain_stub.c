#ifdef _WIN32
#include <windows.h>

/* Forward declaration of user's main. */
int main(void);

/* Provide WinMain as a thin wrapper so linkage succeeds even if the CRT expects WinMain. */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    (void)hInstance; (void)hPrevInstance; (void)lpCmdLine; (void)nShowCmd;
    return main();
}

#endif
