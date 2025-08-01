import java.util.ArrayList;

class Tree {
    private static ArrayList<Integer> list;

    private static void inorderTraversal(Node root) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left);
        list.add(root.data);
        inorderTraversal(root.right);
    }

    public static float findMedian(Node root) {
        list = new ArrayList<Integer>();
        inorderTraversal(root);
        int sizeOfBST = list.size();
        if (sizeOfBST % 2 != 0) {
            return list.get(sizeOfBST / 2);
        }
        // System.out.println(list.get(sizeOfBST/2)+" "+list.get(sizeOfBST/2-1));
        return ((float) list.get(sizeOfBST / 2) + list.get(sizeOfBST / 2 - 1)) / 2;
    }
}

public class Fourteen {

}
