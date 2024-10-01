template < class T>
//GIVEN
class SortBy{

bool sortByTitle;
public: SortBy(bool yes){
   sortByTitle=yes;
  }
 public:
  bool operator()(T a, T b){
    if (sortByTitle) return a<=b;
    else return a<b;
  }
};