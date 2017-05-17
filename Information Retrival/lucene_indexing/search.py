# from lucene import QueryParser, IndexSearcher, IndexReader, StandardAnalyzer, TermPositionVector, SimpleFSDirectory, File, MoreLikeThis, VERSION, initVM, Version
import lucene
import sys
from apt import cache
from ibus import exception

FIELD_CONTENTS = "__text"
# FIELD_PATH = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Datasets/Tweeters_dataset/index/*"

QUERY_STRING = "hello"

STORE_DIR = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Datasets/Tweeters_dataset/index/"

if __name__ == '__main__':
    try:
        lucene.initVM()
        print 'lucene', lucene.VERSION

        # Get handle to index directory
        directory = lucene.SimpleFSDirectory(lucene.File(STORE_DIR))

        # Creates a searcher searching the provided index.
        ireader  = lucene.IndexReader.open(directory, True)

        # Implements search over a single IndexReader.
        # Use a single instance and use it across queries
        # to improve performance.
        searcher = lucene.IndexSearcher(ireader)

        # Get the analyzer
        analyzer = lucene.StandardAnalyzer(lucene.Version.LUCENE_CURRENT)

        # Constructs a query parser. We specify what field to search into.
        queryParser = lucene.QueryParser(lucene.Version.LUCENE_CURRENT, FIELD_CONTENTS, analyzer)

        # Create the query
        query = queryParser.parse(QUERY_STRING)

        # Run the query and get top 50 results
        topDocs = searcher.search(query, 500000)

        # Get top hits
        scoreDocs = topDocs.scoreDocs
        # print scoreDocs
        print "%s total matching documents for %s." % (len(scoreDocs), query)

        # for scoreDoc in scoreDocs:
        #     doc = searcher.doc(scoreDoc.doc)
        #     print "\n"
        #     print doc
        #     print "\n"
            # print doc.get(FIELD_PATH)
    except exception:
        print exception

