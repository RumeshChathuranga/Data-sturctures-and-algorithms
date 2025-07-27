    import com.sun.source.tree.BreakTree;

    import java.sql.SQLOutput;

    public class Tree {

        private class Node{
            private int value;
            private Node leftChild;
            private Node rightChild;

            public Node(int value) {
                this.value = value;
            }
        }
        private Node root;

        public void insert(int value){
            if (root == null){
                root = new Node(value);
                return;
            }
        var current = root;
            while(true){
                if (value < current.value) {
                    if(current.leftChild == null){
                        current.leftChild = new Node(value);
                        break;
                    }
                    current = current.leftChild;
                }
                else {
                    if(current.rightChild == null){
                        current.rightChild = new Node(value);
                        break;
                    }
                    current = current.rightChild;
                }
            }
        }

        public boolean find(int value){
            var current = root;
            while(current != null){
                if ( value < current.value){
                    current = current.leftChild;
                } else if (value > current.value) {
                    current = current.rightChild;
                }else {
                    return true;
                }
            }

            return false;
        }

        public void traversePreOrder(){
            traversePreOrder(root);
        }
        
        public boolean isBinarySearchTree(){
            return isBinarySearchTree(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
        }
        private boolean isBinarySearchTree(Node root, int min, int max){
            if (root == null) return  true;

            if(root.value < min || root.value > max) return  false;

            return isBinarySearchTree(root.leftChild, min, root.value-1) && isBinarySearchTree(root.rightChild, root.value+1, max);
        }

        private void traversePreOrder(Node root){

            if (root == null) return;
            System.out.println(root.value);
            traversePreOrder(root.leftChild);
            traversePreOrder(root.rightChild);
        }

        public void traverseInOrder(){
            traverseInOrder(root);
        }

        public int height(){
            return height(root);
        }
        public int min(){
            return min(root);
        }
        public boolean eqals(Tree other){
            if(other == null) return  false;
            return equals(root, other.root);
        }
        private boolean equals(Node first, Node second){
            if( first == null && second == null)
                return  true;

            if(first != null && second != null){
                return (first.value == second.value &&
                        equals(first.leftChild,second.leftChild) &&
                        equals(first.rightChild,second.rightChild));
            }
            return false;
        }

        private int min(Node root){
            var left = min(root.leftChild);
            var right = min(root.rightChild);
            var min_child = Math.min(left,right);
            return Math.min(min_child,root.value);
        }
        private boolean isLeaf(Node root){
            return root.leftChild == null && root.rightChild == null;
        }

        private int height(Node root){
            if(root == null) return -1;

            if(isLeaf(root))
                return 0;

            return 1+ Math.max(height(root.leftChild),height(root.rightChild));
        }

        private void traverseInOrder(Node root){
            if (root == null) return;

            traverseInOrder(root.leftChild);
            System.out.println(root.value);
            traverseInOrder(root.rightChild);
        }
        public void traversePostOrder(){
            traversePostOrder( root);
        }
        private void traversePostOrder(Node root){
            if (root == null) return;

            traversePostOrder(root.leftChild);
            traversePostOrder(root.rightChild);
            System.out.println(root.value);
        }

    }

