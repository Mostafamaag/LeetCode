
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    
    function dfs(obj){

        if(!obj) return false;
        if(typeof obj !== 'object') return obj;
        
        if(Array.isArray(obj)){
            const res = []
            for(const el of obj){
                const ans = dfs(el);
                if(ans){
                    res.push(ans);
                }
            }
            return res;
        }

        const res = {};
        for(const key in obj){
            const ans = dfs(obj[key]);
            if(ans){
                res[key] = ans;
            }
        }
        return res;
    }

    return dfs(obj);
    
};
