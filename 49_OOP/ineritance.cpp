#include <iostream>
using namespace std;
class parent{
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

class child_1: public parent{
    // x will remain public
    // y will remain protected
    // z will not be accessible
};
class child_2: protected parent{
    // x will be protected
    // y will be protected
    // z will not be accessible
};
class child_3: private parent{
    // x will become private
    // y will become private
    // z will reamin unaccessible
};
int main(){
    return 0;
}