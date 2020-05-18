package sandbox.cognitio.encoding.method.huffman

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
}
