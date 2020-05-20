package sandbox.cognitio.encoding.method.huffman

import sandbox.cognitio.algorythm.tree.binary.Node

class Huffman(
        private val sourceString: String = "beep boop beer!",
        private val alphabet: List<Char> = listOf('!', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z')
) {
    fun frequency(): Map<Char, Int> {

        val letterAndFrequency: LinkedHashMap<Char, Int> = LinkedHashMap()
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

    fun getNodeTree(letterAndFrequency: Map<Char, Int>): Map<Node<String>, Int> {
        val nodeTree: LinkedHashMap<Node<String>, Int> = LinkedHashMap()

        letterAndFrequency.forEach { (t, u) ->
            nodeTree[Node(t.toString())] = u
        }

        return nodeTree
    }
}
