#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "leetcode/symmetric_tree.h"
#include "utils/pretty_print.h"


template<typename T, typename U>
void checkTestCase(const T &received, const U &expected, const std::string &description="") {
    if constexpr (std::is_same_v<bool, T>) {
        std::cerr << std::boolalpha;
    }

    std::cerr << "[Status: ";
    if (expected == received)
        std::cerr << "Success] ";
    else
        std::cerr << "Failed] ";
    std::cerr << "[ Expected |" << expected << "| Received |" << received << "| ]";
    std::cerr << "[Description: " << description << "]" << std::endl;
}

void segfaultHandler(int signum) {
    std::cerr << "Received SEGFAULT while running test case" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    exit(signum);
}

TreeNode* generate_first_tree() {
    TreeNode * a = new TreeNode(1);

    TreeNode * b = new TreeNode(2);
    TreeNode * c = new TreeNode(3);
    TreeNode * d = new TreeNode(4);

    b->left = c;
    b->right = d;

    TreeNode * e = new TreeNode(2);
    TreeNode * f = new TreeNode(3);
    TreeNode * g = new TreeNode(4);
    e->left = g;
    e->right = f;

    a->left = b;
    a->right = e;

    return a;
}

TreeNode* generate_second_tree() {
    TreeNode * a = new TreeNode(1);

    TreeNode * b = new TreeNode(2);
    TreeNode * c = new TreeNode(3);
    b->right = c;

    TreeNode * e = new TreeNode(2);
    TreeNode * f = new TreeNode(3);
    e->right = f;

    a->left = b;
    a->right = e;

    return a;
}

void free_tree(TreeNode* node) {
    if (!node) {
        return;
    }

    if (node->left) {
        free_tree(node->left);
    }

    if (node->right) {
        free_tree(node->right);
    }

    delete node;
}

int main(int argc, char *argv[]) {
    signal(SIGSEGV, segfaultHandler);

    auto first_tree = generate_first_tree();
    checkTestCase(Solution().isSymmetric(first_tree), true, "Case 1");

    auto second_tree = generate_second_tree();
    checkTestCase(Solution().isSymmetric(second_tree), false, "Case 2");

    free_tree(first_tree);
    free_tree(second_tree);

    return 0;
}