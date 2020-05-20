package sandbox.cognitio.algorythm.tree.binary

/**
 * An ADT for a binary search tree.
 * Note that this data type is neither immutable nor thread safe.
 */
class Node<T>(
        val key: T,
        var left: Node<T>? = null,
        var right: Node<T>? = null
) {

    /**
     * Returns a json string representation of the object.
     */
    override fun toString(): String {
        return StringBuilder("{")
                .append("\"key\" : \"$key\",")
                .append("\"left child\" : ${left.toString()},")
                .append("\"right child\" : ${right.toString()}")
                .append("}")
                .toString()
    }
}
