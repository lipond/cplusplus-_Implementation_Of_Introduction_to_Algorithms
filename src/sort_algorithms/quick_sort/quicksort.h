/*
 * Copyright 2016- huaxz <huaxz1986@163.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: huaxz1986@163.com (huaxz)
 */
#ifndef QUICKSORTE_H
#define QUICKSORTE_H

namespace IntrodunctionToAlgorithm
{
    namespace SortAlgorithm
    {
        //! quick_sort： 算法导论第7章
        /*!
         * \param begin : 待排序序列的起始迭代器（也可以是指向数组中某元素的指针）
         * \param end: 待排序序列的终止迭代器（也可以是指向数组中某元素的指针）
         * \param compare: 一个可调用对象，可用于比较两个对象的小于比较，默认为std::less<T>
         * \return void
         *
         * - 快速排序思想，假设对数组A[p...r]排序：
         *   - 分解：将数组A[p...r]划分为两个（可能为空）的子数组A[p...q-1]个A[q+1...r]，使得A[q]大于前面一个数组中每个元素，小于后面一个数组中每个元素
         *   - 解决： 对 A[p...q-1]和A[q+1...r]递归调用快速排序
         * - 最坏时间复杂度 O(n^2)， 期望时间复杂度 O(nlgn)。它平均性能非常好，是实际排序应用中最好的选择
         * - 原地排序
        */
        template<typename Iterator,typename Compare=std::less<typename std::iterator_traits<Iterator>::value_type>>
                        void quick_sort(Iterator begin,Iterator end,Compare compare=Compare())
        {
            //typedef typename std::iterator_traits<Iterator>::value_type T;// 迭代器指向对象的值类型
            if(end-begin<=1)
                return;
            auto smaller_next=begin;  //指向比key小的元素区间的下一个(即大于等于key元素区间的第一个），其中key为序列最后一个元素
            auto current=begin;  //指向当前待处理的元素
            while(current!=end-1)
            {
                if(compare(*current,*(end-1)))
                {
                    std::swap(*smaller_next,*current);
                    smaller_next++;
                }
                current++;
            }
            std::swap(*smaller_next,*(end-1));
            quick_sort<Iterator>(begin,smaller_next,compare);
            quick_sort<Iterator>(smaller_next+1,end,compare);
        }
    }
}
#endif // QUICKSORTE_H

