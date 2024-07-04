

#include "traverse_ast.hpp"
#include "token.hpp"

#include "ast_node_headers.hpp"


#pragma execution_character_set( "utf-8" )


// ├───
// ────  // 4 characters
// └───

std::string tab = "|";

void add_space_tab()
{
    tab += "   ";
}

void delete_space_tab()
{
    if (tab.size() < 4)
    {
        return;
    }
    tab = tab.substr(0, tab.size() - 4);
}

void Traverse::traverse(std::unique_ptr<AstNode>& statement)
{
    statement->accept(*this);
}

std::any Traverse::visitFunctionCallNode(FunctionCallExpr& functionCallExpr)
{
    std::cout << tab + "FunctionCallExprNode (" + functionCallExpr.identifier + ")" << std::endl;
    std::cout << tab + "└─── Arguments" << std::endl;
    add_space_tab();
    for (auto& arg : functionCallExpr.arguments)
    {
        arg->accept(*this);
    }
    delete_space_tab();
    return std::any();
}

std::any Traverse::visitBlockStmtNode(BlockStmtNode& blockStmtNode)
{
    std::cout << tab + "BlockStatementNode" << std::endl;
    size_t stmt_counter = 0;
    for (auto& stmt : blockStmtNode.stmts)
    {
        if (blockStmtNode.stmts.size() == stmt_counter - 1)
        {
            std::cout << tab + "└───";
        }
        else
        {
            std::cout << tab + "├───";
        }
        stmt_counter++;
        stmt->accept(*this);
        std::cout << std::endl;
    }
    return std::any();
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
    return std::any();
}

std::any Traverse::visitBoolNode(BoolNode& boolNode)
{
    std::cout << tab + "BoolNode" << std::endl;
    return std::any();
}

std::any Traverse::visitNumberNode(NumberNode& numberNode)
{
    std::cout << tab + "NumberNode" << std::endl;
    return std::any();
}

std::any Traverse::visitStringNode(StringNode& stringNode)
{
    std::cout << tab + "StringNode" << std::endl;
    return std::any();
}

std::any Traverse::visitIdentifierNode(IdentifierNode& identifierNode)
{
    std::cout << tab + "IdentifierNode" << std::endl;
    return std::any();
}

std::any Traverse::visitUnaryNode(UnaryNode& unaryNode)
{
    std::cout << tab + "UnaryNode" << std::endl;
    return std::any();
}

std::any Traverse::visitIfStmtNode(IfStmtNode& ifStmtNode)
{
    std::cout << tab + "IfStatmentNode" << std::endl;
    std::cout << tab + "├───";
    add_space_tab();
    ifStmtNode.expression->accept(*this);
    delete_space_tab();
    std::cout << tab + "└───";
    add_space_tab();
    ifStmtNode.blockStmt->accept(*this);
    delete_space_tab();
    return std::any();
}

std::any Traverse::visitPrintStmt(PrintStmtNode& printStmtNode)
{
    std::cout << tab + "PrintStatementNode" << std::endl;
    std::cout << tab + "└───";
    add_space_tab();
    printStmtNode.expression->accept(*this);
    delete_space_tab();
    return std::any();
}

std::any Traverse::visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode)
{
    std::cout << tab + "VarDeclarationNode";
    return std::any();
}

std::any Traverse::visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode)
{
    std::cout << tab + "VarAssignmentNode";
    return std::any();
}