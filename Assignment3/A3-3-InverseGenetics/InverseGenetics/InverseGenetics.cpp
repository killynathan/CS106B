/* File: InverseGenetics.cpp
 *
 * A program that, given a sequence of amino acids, returns all possible
 * RNA strands that could encode that amino acid sequence.
 */
#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "map.h"
#include "console.h"
using namespace std;

/* Function: allRNAStrandsFor(string protein,
 *                            Map<char, Set<string> >& codons);
 * Usage: foreach (string rna in allRNAStrandsFor("PARTY", codons);
 * ==================================================================
 * Given a protein and a map from amino acid codes to the codons for
 * that code, returns all possible RNA strands that could generate
 * that protein.
 */
Set<string> allRNAStrandsFor(string protein, Map<char, Set<string> >& codons);

void helper(string protein, string current, Map<char, Set<string> >& codons, Set<string>& strands);

/* Function: loadCodonMap();
 * Usage: Map<char, Lexicon> codonMap = loadCodonMap();
 * ==================================================================
 * Loads the codon mapping table from a file.
 */
Map<char, Set<string> > loadCodonMap();

int main() {
	/* Load the codon map. */
	Map<char, Set<string> > codons = loadCodonMap();
	Set<string> test = allRNAStrandsFor("KWS", codons);
	foreach (string rna in test) {
		cout << rna << endl;
	}
	/* TODO: Add testing code here! */
	return 0;
}

Set<string> allRNAStrandsFor(string protein, Map<char, Set<string> >& codons) {
	// TODO: Implement this function!
	Set<string> strands;
	helper(protein, "", codons, strands);
	return strands;
}

void helper(string protein, string current, Map<char, Set<string> >& codons, Set<string>& strands) {
	if (protein == "") {
		strands += current;
	}
	else {
		foreach (string codon in codons[protein[0]]) {
			cout << codon << endl;
			helper(protein.substr(1), current + codon, codons, strands);
		}
	}
}

/* You do not need to change this function. */
Map<char, Set<string> > loadCodonMap() {
	ifstream input("codons.txt");
	Map<char, Set<string> > result;
		
	/* The current codon / protein combination. */
	string codon;
	char protein;
	
	/* Continuously pull data from the file until all data has been
	 * read.  We did not cover this syntax in class, but it means
	 * "while reading a codon/protein pair succeeds, add the pair to
	 * the map."
	 */
	while (input >> codon >> protein) {
		result[protein] += codon;
	}
	
	return result;
}

