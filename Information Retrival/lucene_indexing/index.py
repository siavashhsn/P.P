import lucene
import glob
import os



if __name__ == '__main__':
    
    INDEX_DIR = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Datasets/Tweeters_dataset/index"

    FILES_TO_INDEX = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Datasets/Tweeters_dataset/twitts/*"
    # FILES_TO_INDEX = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Datasets/Tweeters_dataset/Test(100)/*"

    # Initialize lucene and JVM
    lucene.initVM()

    print "lucene version is:", lucene.VERSION
    exit()
    # Get the analyzer
    analyzer = lucene.StandardAnalyzer(lucene.Version.LUCENE_CURRENT)

    # Get index storage
    store = lucene.SimpleFSDirectory(lucene.File(INDEX_DIR))

    # Get index writer
    writer = lucene.IndexWriter(store, analyzer, True, lucene.IndexWriter.MaxFieldLength.LIMITED)

    for files in glob.glob(FILES_TO_INDEX):
        try:
            with open(files) as f:
                t = f.read()

                # print t

                s = list(t.split("\n"))
                # print s

                b = 0

                d = []
                for j in s:
                    if "Text:" in j:
                        i = j.replace('Text: ', '')
                        d.append(i)
                        b += 1
                    if "ID:" in j:
                        i = j.replace('ID: ', '')
                        d.append(i)
                        b += 1


                    if b == 2:
                        b = 0
                        # create a document that would we added to the index
                        doc = lucene.Document()
                        # print d
                        # Add a field to this document
                        # field = lucene.Field("title", "India", lucene.Field.Store.YES, lucene.Field.Index.ANALYZED)
                        name = os.path.basename(f.name)
                        
                        field1 = lucene.Field("__id", d[1], lucene.Field.Store.YES, lucene.Field.Index.ANALYZED)
                        doc.add(field1)
                        field2 = lucene.Field("__text", d[0], lucene.Field.Store.YES, lucene.Field.Index.ANALYZED)
                        doc.add(field2)
                        field3 = lucene.Field("__pid", name, lucene.Field.Store.YES, lucene.Field.Index.ANALYZED)
                        doc.add(field3)
                        # Add this field to the document

                        # Add the document to the index
                        writer.addDocument(doc)
                        d = []
                        # print name
        except():
            # print "Failed in indexDocs:", e
            print "Oops!!!..."
            continue

    writer.commit()
    writer.close()
