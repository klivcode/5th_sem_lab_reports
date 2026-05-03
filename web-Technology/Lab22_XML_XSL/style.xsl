<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
        <head>
            <title>Bookstore XSLT</title>
            <style>   
                table {
                    border-collapse: collapse;
                    width: 60%;
                    margin: 20px auto;
                    font-family: Arial;
                }
                th, td {
                    border: 1px solid #ddd;
                    padding: 8px;
                    text-align: left;
                }
                th {
                    background-color: #4CAF50;
                    color: white;
                }
                tr:nth-child(even) {
                    background-color: #f2f2f2;
                }
            </style>
        </head>

        <body>
            <h2 style="text-align:center;">My Bookstore</h2>

            <table>
                <tr>
                    <th>Title</th>
                    <th>Author</th>
                    <th>Price ($)</th>
                    <th>ISBN</th>
                </tr>

                <xsl:for-each select="bookstore/book">
                    <tr>
                        <td><xsl:value-of select="title"/></td>
                        <td><xsl:value-of select="author"/></td>
                        <td><xsl:value-of select="price"/></td>
                        <td><xsl:value-of select="isbn"/></td>
                    </tr>
                </xsl:for-each>

            </table>
        </body>
        </html>
    </xsl:template>

</xsl:stylesheet>