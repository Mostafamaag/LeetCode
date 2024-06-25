/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
    const groupedArray = {};

    this.forEach((obj) => {
        const key = fn(obj);
        if(!groupedArray[key]) groupedArray[key] = [];
        groupedArray[key].push(obj);
    })
    
    return groupedArray;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
