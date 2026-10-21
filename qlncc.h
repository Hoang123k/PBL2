#include "Ncc.h"
#include<vector>
class qlncc{
    private:
        int soluong_ncc;
        vector<Ncc> ql_ncc;
    public:
        qlncc();
        ~qlncc();

        friend void docfile(qlncc&, const string&);
        void show();
};