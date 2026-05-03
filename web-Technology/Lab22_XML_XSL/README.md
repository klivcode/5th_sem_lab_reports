# Lab 22 - XML and XSL

**Aim/Objectives**: Create an XML file and an XSL stylesheet to transform and display the XML data as an HTML table.

**Theory**: XML is used to store and transport data. XSLT (Extensible Stylesheet Language Transformations) is used to transform XML documents into HTML format directly in the browser using rules (templates).

**Procedure/Steps**:
1. Create `books.xml` with `<bookstore>` as root and `<book>` children containing title, author, price, and isbn.
2. Link the XSL file using `<?xml-stylesheet type="text/xsl" href="style.xsl"?>`.
3. Create `style.xsl`. Define `<xsl:template match="/">` to output standard HTML structure.
4. Use `<xsl:for-each>` to loop through books and output table rows `<tr>` and cells `<td>`.

**Source Code**: See `books.xml` and `style.xsl`.

**Output description**: When `books.xml` is opened in a web browser, the browser applies the XSL transformation and displays a clean, styled HTML table containing the book data.

**Conclusion**: Learned how to present raw XML data aesthetically using XSLT.\n