---
description: Setup
---

# MFCtrl

## Getting Super Powers

Becoming a super hero is a fairly straight forward process:

```
$ git clone https://github.com/zunamidev/MFCtrl.git
```

{% hint style="warning" %}
Please submit an issue if you're not happy with yours.
{% endhint %}

How to use it?

{% code title="main.cpp" %}
```cpp
#include "lib/MFCtrl.h"

int main(int argc, const char * argv[]) {
    MFCtrl MF(12, 23, 3);
    std::cout << MF.sendData(16000);
    std::cout << MF.readData(16000);
    MF.getInfo();

    return 0;
}
```
{% endcode %}



