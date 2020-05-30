package sandbox.encoding.method.huffman

import sandbox.encoding.method.algorythm.tree.binary.Node

class Huffman(
        private val sourceString: String = "beep boop beer!"
) : AbstractHuffman() {
    fun frequency(): Map<Char, Int> = super.frequency(sourceString)

    /**
     * На входе дерево и сообщение,
     * на выходе - исходник
     */
    fun decodeTree(huffmanTree: Node<String>, encodedBytes: String): String {
        var noda = huffmanTree
        var message = ""
        encodedBytes.forEach {
            when (it) { // Развилка
                '0' -> noda = noda.left!!
                '1' -> noda = noda.right!!
            }
            if (noda.left == null && noda.right == null) { // Конец пути
                message = message.plus(noda.key) // Сокровище
                noda = huffmanTree  // Передвигаю фишку на старт
            }
        }
        return message
    }
}
