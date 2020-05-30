package sandbox.encoding.method.algorythm.tree.binary

import sandbox.encoding.method.algorythm.SeemsLikeAStaticOne

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
     * Присваеват код каждому звену бинарного дерева
     */
    fun huffmanCodes(code: String) {
        if (left == null && right == null) {
            SeemsLikeAStaticOne.codeKey(Pair(key.toString(), code))
            return
        }
        left!!.huffmanCodes(code.plus("0"))
        right!!.huffmanCodes(code.plus("1"))
    }

    /**
     * Присваеват код каждому звену бинарного дерева
     * Pair.first - значение
     * Pair.second - двоичный код
     */
    fun smartHuffmanCodes(code: String = "", recursiveList: MutableList<Pair<String, String>> = mutableListOf())
            : List<Pair<String, String>> {
        if (left != null)
            recursiveList.addAll(left!!.smartHuffmanCodes(code.plus("0")))
        if (right != null)
            recursiveList.addAll(right!!.smartHuffmanCodes(code.plus("1")))
        return recursiveList.plus(Pair(key.toString(), code))
    }

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
