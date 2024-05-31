#include "traverse_ast.hpp"
#include "ast_node_headers.hpp"
#include "token.hpp"

// ├───
// ────  // 4 characters
// └───

std::string tab = "";

void add_space_tab()
{
    tab += "    ";
}

void delete_space_tab()
{
    if (tab.size() < 4)
    {
        return;
    }
    tab.substr(0, tab.size() - 4);
}

std::any Traverse::visitFunctionCallNode(FunctionCallExpr& functionCallExpr)
{
    std::cout << tab + "FunctionCallExprNode (" + functionCallExpr.identifier + ")" << std::endl;
    
}

std::any Traverse::visitBlockStmtNode(BlockStmtNode& blockStmtNode)
{
    std::cout << tab + "BlockStatementNode" << std::endl;
    std::cout << tab + "└─── ";
    add_space_tab();
    for (auto& stmt : blockStmtNode.stmts)
    {
        stmt->accept(*this);
    }
    delete_space_tab();
}

std::any Traverse::visitBinaryExpression(BinaryExpression& binaryExpression)
{
    std::cout << tab + "BinaryExpressionNode (" + token_name(binaryExpression.op) + ")" << std::endl;

    std::string character = "├─── ";
    if (binaryExpression.right == nullptr)
    {
        character = "└─── ";
    }
    std::cout << tab + character;
    add_space_tab();
    binaryExpression.left->accept(*this);
    delete_space_tab();
    std::cout << tab + "└─── ";
    add_space_tab();
    binaryExpression.right->accept(*this);
    delete_space_tab();
}

std::any Traverse::visitBoolNode(BoolNode& boolNode)
{
    std::cout << tab + "BoolNode";
}

std::any Traverse::visitNumberNode(NumberNode& numberNode)
{
    return std::any();
}

std::any Traverse::visitStringNode(StringNode& stringNode)
{
    return std::any();
}

std::any Traverse::visitIdentifierNode(IdentifierNode& identifierNode)
{
    return std::any();
}

std::any Traverse::visitUnaryNode(UnaryNode& unaryNode)
{
    return std::any();
}

std::any Traverse::visitIfStmtNode(IfStmtNode& ifStmtNode)
{
    return std::any();
}

std::any Traverse::visitPrintStmt(PrintStmtNode& printStmtNode)
{
    return std::any();
}

std::any Traverse::visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode)
{
    return std::any();
}

std::any Traverse::visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode)
{
    return std::any();
}
