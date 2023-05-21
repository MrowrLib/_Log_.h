#include <_Log_.h>

// _LogToFile_("Example.log");

int main() {
    _Log_("Hello {}", "World");
    // _LogToFile_("");
    _Log_("Hello {}", "World AGAIN");
}
