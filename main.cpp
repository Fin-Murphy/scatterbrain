#include "main.h"


int main() {
terminal mTerm;

std::vector<std::string> tasks = mTerm.fQuery();
mTerm.termDisp(mTerm);

return 0;
}

