

#include "functioncallexpr.hpp"

FunctionCallExpr::FunctionCallExpr(std::string identifier, std::vector<std::unique_ptr<AstNode>> arguments)
{
    this->arguments = std::move(arguments);
    this->identifier = identifier;
}

std::any FunctionCallExpr::accept(Visitor& visitor)
{
    return visitor.visitFunctionCallNode(*this);
}
