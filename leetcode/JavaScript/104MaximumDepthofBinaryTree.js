// 104. Maximum Depth of Binary Tree

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Solution: 

const maxDepth = (root)=> {
    let depth = 0;
    let queue = [root]
    
    if(!root) return 0;
    
    while(queue.length){
        let len = queue.length
        
        for(let i = 0; i < len; i++){
            let current = queue.shift()
            
            if(current.right) queue.push(current.right)
            if(current.left) queue.push(current.left)
        }
        depth++
    }
    return depth
}