/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    filterRes = [];
    for(let i = 0; i < arr.length; i++){
        if(fn(arr[i],i)) filterRes.push(arr[i]);
    }
    return filterRes;
};
