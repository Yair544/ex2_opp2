#pragma once
#include <string>

template<typename T>
class Validator {
public:
    virtual bool validate(const T& value) const = 0; // פונקציה וירטואלית טהורה
    virtual ~Validator() = default; // דה-קונסטרקטור וירטואלי
};
