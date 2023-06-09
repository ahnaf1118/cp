# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def buildTree(self, preorder, inorder):
        if len(inorder) == 0: return None
        INDEX = inorder.index(preorder.pop(0))
        root = TreeNode(inorder[INDEX])
        root.left = self.buildTree(preorder, inorder[:INDEX])
        root.right = self.buildTree(preorder, inorder[INDEX+1:])
        return root
