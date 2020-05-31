package sandbox.encoding.method.arithmetic

import java.math.BigInteger
import java.util.*


class ArithmeticCoding {
    private class Triple<A, B, C> internal constructor(var a: A, var b: B, var c: C)

    private class Freq : HashMap<Char?, Long?>() { //"type alias"
    }

    fun index(){
        val radix: Long = 10
        val fmt = "%-25s=> %19s * %d^%s\n"
        val strings = arrayOf("beep boop beer!", "abracadabra", "to be or not to be or want to be or not?")
        for (str in strings) {
            val encoded: Triple<BigInteger, Int, Freq>? = arithmeticCoding(str, radix)
            val dec = encoded?.a?.let { arithmeticDecoding(it, radix, encoded.b, encoded.c) }
            if (encoded != null) {
                System.out.printf(fmt, str, encoded.a, radix, encoded.b)
            }
            if (str != dec) throw RuntimeException("\tHowever that is incorrect!")
        }

    }

    private fun cumulativeFreq(freq: Freq): Freq {
        var total: Long = 0
        val cf = Freq()
        for (i in 0..255) {
            val c = i.toChar()
            val v = freq[c]
            if (v != null) {
                cf[c] = total
                total += v
            }
        }
        return cf
    }

    private fun arithmeticCoding(str: String, radix: Long): Triple<BigInteger, Int, Freq>? {
        // Convert the string into a char array
        val chars = str.toCharArray()

        // The frequency characters
        val freq = Freq()
        for (c in chars) {
            if (!freq.containsKey(c)) freq[c] = 1L else freq[c] = freq[c]!! + 1
        }

        // The cumulative frequency
        val cf = cumulativeFreq(freq)

        // Base
        val base = BigInteger.valueOf(chars.size.toLong())

        // LowerBound
        var lower = BigInteger.ZERO

        // Product of all frequencies
        var pf = BigInteger.ONE

        // Each term is multiplied by the product of the
        // frequencies of all previously occurring symbols
        for (c in chars) {
            val x = BigInteger.valueOf(cf[c]!!)
            lower = lower.multiply(base).add(x.multiply(pf))
            pf = pf.multiply(BigInteger.valueOf(freq[c]!!))
        }

        // Upper bound
        val upper = lower.add(pf)
        var powr = 0
        val bigRadix = BigInteger.valueOf(radix)
        while (true) {
            pf = pf.divide(bigRadix)
            if (pf == BigInteger.ZERO) break
            powr++
        }
        val diff = upper.subtract(BigInteger.ONE).divide(bigRadix.pow(powr))
        return Triple(diff, powr, freq)
    }

    private fun arithmeticDecoding(num: BigInteger, radix: Long, pwr: Int, freq: Freq): String? {
        val powr = BigInteger.valueOf(radix)
        var enc = num.multiply(powr.pow(pwr))
        var base: Long = 0
        for (v in freq.values) base += v!!

        // Create the cumulative frequency table
        val cf = cumulativeFreq(freq)

        // Create the dictionary
        val dict: MutableMap<Long?, Char?> = HashMap()
        for ((key, value) in cf) dict[value] = key

        // Fill the gaps in the dictionary
        var lchar: Long = -1
        for (i in 0 until base) {
            val v = dict[i]
            if (v != null) {
                lchar = v.toLong()
            } else if (lchar != -1L) {
                dict[i] = lchar.toChar()
            }
        }

        // Decode the input number
        val decoded = StringBuilder(base.toInt())
        val bigBase = BigInteger.valueOf(base)
        for (i in base - 1 downTo 0) {
            val pow = bigBase.pow(i.toInt())
            val div = enc.divide(pow)
            val c = dict[div.longValueExact()]
            val fv = BigInteger.valueOf(freq[c]!!)
            val cv = BigInteger.valueOf(cf[c]!!)
            val diff = enc.subtract(pow.multiply(cv))
            enc = diff.divide(fv)
            decoded.append(c)
        }
        // Return the decoded output
        return decoded.toString()
    }
}