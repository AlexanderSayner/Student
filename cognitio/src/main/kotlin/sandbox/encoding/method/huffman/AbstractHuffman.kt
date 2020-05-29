package sandbox.encoding.method.huffman

import sandbox.encoding.method.algorythm.tree.binary.Node

abstract class AbstractHuffman {
    fun frequency(sourceString: String): Map<Char, Int> {

        val letterAndFrequency = LinkedHashMap<Char, Int>()
        sourceString.forEach {
            val number = letterAndFrequency.getOrPut(it) { 0 }
            if (letterAndFrequency.getValue(it) == 0) {
                letterAndFrequency[it] = 1
            } else {
                letterAndFrequency[it] = number + 1
            }
        }

        return letterAndFrequency.toList()
                .sortedBy { (_, value) -> value }
                .toMap()
    }

    fun getNodeTree(letterAndFrequency: Map<Char, Int>): Map<Node<String>, Int> {
        val nodeTree: LinkedHashMap<Node<String>, Int> = LinkedHashMap()

        letterAndFrequency.forEach { (t, u) ->
            nodeTree[Node(t.toString())] = u
        }

        return nodeTree
    }

    fun tree(letterAndFrequency: Map<Node<String>, Int>): Node<String>? {

        var huffmanTree = letterAndFrequency
        var iterator = huffmanTree.iterator()
        while (huffmanTree.size >= 2 && iterator.hasNext()) {
            val nextLeft = iterator.next()
            val nextRight = iterator.next()
            val splice = Node(
                    nextLeft.key.key
                            .plus(nextRight.key.key))
            splice.left = nextLeft.key
            splice.right = nextRight.key
            huffmanTree = huffmanTree
                    .minus(nextLeft.key)
                    .minus(nextRight.key)
                    .plus(Pair(splice, nextLeft.value + nextRight.value))
                    .toList()
                    .sortedBy { (_, value) -> value } // sorting by the priority
                    .toMap()
            iterator = huffmanTree.iterator() // go from the beginning
        }

        return huffmanTree.iterator().next().key
    }

    /**
     * Кодирует в Хаффмана по словарю
     */
    fun encodeMessage(codeKey: Map<String, String>, message: String): String {
        var encode = ""
        message.forEach {
            encode = encode.plus(codeKey[it.toString()])
        }
        return encode
    }
}
