#include "model.h"

namespace s21 {

void Model::MoveElement_(std::stack<StackNode>& src, std::stack<StackNode>& dest)
{
    StackNode tmp = src.top();
    dest.emplace(tmp.data, tmp.priority, tmp.type);
    src.pop();
}

void Model::SpliceOperators_(std::stack<StackNode>& src, std::stack<StackNode>& dest)
{
    while (isOperator(src.top().type))
    {
        MoveElement_(src, dest);
    }
}

void Model::SpliceNumbers_(std::stack<StackNode>& src, std::stack<StackNode>& dest)
{
    while (src.top().type == kNumber)
    {
        MoveElement_(src, dest);
    }
}

}  // namespace s21
