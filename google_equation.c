#include <iostream>

typedef struct tagCharItem{
    char c;
    int value;
    bool leading;
}CHAR_ITEM;

typedef struct tagCharValue{
    bool used;
    int value;
}CHAR_VALUE;

typedef void (*CHarListResultFuncPtr)(CHAR_ITEM ci[]);

void SearchingResult(CHAR_ITEM ci[], CHAR_VALUE cv[],
                     int index, CharListResultFuncPtr callback){
    int max_char_count = 9;
    if(index == max_char_count){
        callback(ci);
        return;
    }

    for(int i = 0; i < max_char_count; ++i){
        if(IsValueValid(ci[index], cv[i])){
            cv[i].used = true;
            ci[index].value = cv[i].value;
            SearchingResult(ci,cv,index + 1, callback);
            cv[i].used = false;
        }
    }
}


bool IsValueValid(CHAR_ITEM charItem, CHAR_VALUE charValue){


}

void OnCharListReady(CHARITEM ci[]){
    char *minuend = "WWWDOT";
    char *subtrahead = "GOOGLE";
    char *diff = "DOTCOM";

    int m = MakeIntegerValue(ci, minuend);
    int s = MakeIntegerValue(ci, substrahead);
    int d = MakeIntegerValue(ci, diff);

    if(m - s == d){
        std::cout << m << " - " << s << "=" << d << std::endl;
    }
}


int main(){
    CHAR_ITEM charItem[] = { {'W',-1,true}, {'D', -1, true}, {'O',-1, false},
                             {'T', -1, false}, {'G', -1, true}, {'L', -1, false},
                             {'E', -1, false}, {'C', -1, false}, {'M', -1, false}};

    CHAR_VALUE charValue[] = { {false, 0}, {false, 1}, {false, 2}, {false, 3}, {false, 4}
                               {false, 5}, {false, 6}, {false, 7}, {false, 8}, {false, 9}};

    SearchingResult(charItem, charValue,0,OnCharListReady);
    return;

}




