#include <readline/readline.h>
#include <readline/history.h>

int main() {
    add_history("First command");
    add_history("Second command");

    return 0;
}