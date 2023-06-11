#include "model.h"

namespace s21 {

void Model::moveElement(std::stack<StackNode>& src, std::stack<StackNode>& dest)
{
    StackNode tmp = src.top();
    dest.emplace(tmp.data, tmp.priority, tmp.type);
    src.pop();
}

void Model::spliceOperators(std::stack<StackNode>& src, std::stack<StackNode>& dest)
{
    while (isOperator(src.top().type))
    {
        moveElement(src, dest);
    }
}

void Model::spliceNumbers(std::stack<StackNode>& src, std::stack<StackNode>& dest)
{
    while (src.top().type == kNumber)
    {
        moveElement(src, dest);
    }
}

}  // namespace s21
