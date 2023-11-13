#include "reader/FileInput.h"
#include "parser/AbstractSyntaxTreeBuilder.h"
#include "runner/ScopeInterpreter.h"

int main(int argc, char *argv[], char *argvs[]) {
    if (argc < 2) {
        std::cerr << "Error! Expected script file name, e.g.:\nt7tp1_run script01.sc";
        return 1;
    }

    auto command = argv[1];
    if (strcmp(command, "help") == 0 || strcmp(command, "?") == 0) {
        std::cout << "Help";
        return 0;
    }

    try {
        auto fileInput = new FileInput;
        auto script = fileInput->getFileContents(command);

        auto astBuilder = new AbstractSyntaxTreeBuilder;
        auto scope = astBuilder->build(script);

        auto scopeInterpreter = new ScopeInterpreter();
        scopeInterpreter->run(&scope);
    } catch(std::runtime_error ex) {
        std::cerr << "Interpreting error: " << ex.what();
    }
}
