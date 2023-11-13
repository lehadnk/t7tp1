project(t7tp1_src)

set(HEADER_FILES runner/ScopeInterpreter.h dto/Scope.h dto/Variable.h enum/VariableType.h
        parser/AbstractSyntaxTreeBuilder.cpp
        parser/AbstractSyntaxTreeBuilder.h
        parser/Lexer.cpp
        parser/Lexer.h)
set(SOURCE_FILES runner/ScopeInterpreter.cpp
        parser/AbstractSyntaxTreeBuilder.cpp
        parser/AbstractSyntaxTreeBuilder.h
        parser/Lexer.cpp
        parser/Lexer.h
        dto/Lexeme.h
        enum/TokenType.h
        dto/AstNode.h
        runner/handler/AbstractOperationHandler.cpp
        runner/handler/AbstractOperationHandler.h
        runner/handler/ForLoopHandler.cpp
        runner/handler/ForLoopHandler.h
        runner/handler/IfConditionHandler.cpp
        runner/handler/IfConditionHandler.h
        runner/handler/InputHandler.cpp
        runner/handler/InputHandler.h
        runner/handler/AssignmentHandler.cpp
        runner/handler/AssignmentHandler.h
        runner/handler/ArithmeticOperatorHandler.cpp
        runner/handler/ArithmeticOperatorHandler.h
        runner/handler/VariableDeclarationHandler.cpp
        runner/handler/VariableDeclarationHandler.h
        runner/handler/IdentifierHandler.cpp
        runner/handler/IdentifierHandler.h
        runner/handler/PrintOperationHandler.cpp
        runner/handler/PrintOperationHandler.h
        runner/handler/ComparisonOperatorHandler.cpp
        runner/handler/ComparisonOperatorHandler.h
        reader/FileInput.cpp
        reader/FileInput.h)

add_library(t7tp1_src STATIC ${SOURCE_FILES} ${HEADER_FILES})