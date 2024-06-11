/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const memo = {};

    return function(...args) {
        //let idx = args
        let idx = JSON.stringify(args);
        if(idx in memo) return memo[idx];

        let res = fn(...args);
        memo[idx] = res;

        return res;
    }
}


// /** 
//  * let callCount = 0;
//  * const memoizedFn = memoize(function (a, b) {
//  *	 callCount += 1;
//  *   return a + b;
//  * })
//  * memoizedFn(2, 3) // 5
//  * memoizedFn(2, 3) // 5
//  * console.log(callCount) // 1 
//  */
 

