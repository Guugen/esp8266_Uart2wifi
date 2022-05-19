//
// Created by HN on 2022/5/19.
//

#include "data_pool.h"


data_pool* data_pool_init(int l){
    data_pool Ptr;
    Ptr.poolPtr = (int*)malloc(l*sizeof(int)); //分配l个int大小的内存空间
    /*分配成功，初始化data_pool*/
    if(Ptr.poolPtr){
        Ptr.length = l;
        Ptr.last = 0;
        return &Ptr;
    }

        /*分配失败，返回错误信息*/
    else{
        printf("内存分配失败");
        return NULL;
    }
}
