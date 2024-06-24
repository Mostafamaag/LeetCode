/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    size = 0;
    for(const _ in obj) size++;
    if(!size) return true;
    return false;
};
