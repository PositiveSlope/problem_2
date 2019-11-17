#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree, demo) {
    //        3
    //      /   \
    //     1     5
    //   /  \   /
    //  2   7  5
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

/*//no deconstructor test, as long as no memleak
TEST(tree, deconstructInPre){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));
    BinaryTree<int> tree(root);
    //~BinaryTree();
}*/

TEST(traverse,inOrder){
    //        3
    //      /   \
    //     1     5
    //   /  \   /
    //  2   7  5
    BinaryTree<int> empty(nullptr);
    std::vector<int> emptyTraverse=empty.traverseInOrder();
    std::vector<int> expectedEmptyResult;
    ASSERT_TRUE(emptyTraverse==expectedEmptyResult);

    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);
    std::vector<int> expectedResult={2,1,7,3,5,5};

    std::vector<int> theResult=tree.traverseInOrder();

    ASSERT_EQ(theResult,expectedResult);
}

TEST(traverse, postOrder){
    //        3
    //      /   \
    //     1     5
    //   /  \   /
    //  2   7  5
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);
    std::vector<int> expectedResult={2,7,1,5,5,3};

    std::vector<int> theResult=tree.traversePostOrder();

    ASSERT_EQ(theResult,expectedResult);
}

TEST(least, leastCommon){
    //        4
    //      /   \
    //     8     6
    //   /  \   / \
    //  7   3  2   9
    TreeNode<int>* root = new TreeNode<int>(4);
    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));

    BinaryTree<int> tree(root);
    ASSERT_TRUE(tree.LCA(4, 4) == 4);
    ASSERT_TRUE(tree.LCA(7, 7) == 7);
    ASSERT_TRUE(tree.LCA(7, 3) == 8);
    ASSERT_TRUE(tree.LCA(7, 8) == 8);
    ASSERT_TRUE(tree.LCA(8, 6) == 4);
    ASSERT_TRUE(tree.LCA(3, 2) == 4);

}