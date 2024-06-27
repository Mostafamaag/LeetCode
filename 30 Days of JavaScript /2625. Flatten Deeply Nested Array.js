/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const res = [];

    function helper(arr, depth){
        for(const el of arr){
            if(typeof el === 'object' && depth < n){
                helper(el, depth + 1);
            }
            else{
                res.push(el);
            }
        }
    }
    helper(arr, 0);
    
    return res;
};
