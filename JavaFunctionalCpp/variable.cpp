#include "variable.hpp"

DataType tokent2datatype(Token_t token)
{
    switch (token)
    {
    case INT_TYPE:
        return DT_INT;
    }

    return DT_NOT_VALID;
}
