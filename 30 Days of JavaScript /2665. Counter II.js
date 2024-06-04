/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let curCounter = init
    return{
        increment: () => {
            return ++curCounter;
        },
        decrement: () => {
            return --curCounter;
        },
        reset: () => {
            curCounter = init;
            return curCounter;
        }
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
