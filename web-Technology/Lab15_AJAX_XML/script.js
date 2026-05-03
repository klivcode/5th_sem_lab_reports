function loadXMLData() {
    fetch("data.xml")
        .then(response => {
            if (!response.ok) {
                throw new Error("Failed to load XML");
            }
            return response.text();
        })
        .then(str => {
            const parser = new DOMParser();
            const xmlDoc = parser.parseFromString(str, "application/xml");
            parseAndDisplayXML(xmlDoc);
        })
        .catch(err => {
            document.getElementById("output").innerHTML = "Error loading XML data.";
            console.error(err);
        });
}

function getTagValue(parent, tag) {
    const el = parent.getElementsByTagName(tag)[0];
    return el ? el.textContent : "N/A";
}

function parseAndDisplayXML(xmlDoc) {
    const employees = xmlDoc.getElementsByTagName("employee");

    let htmlOutput = "<h3>Employee List</h3>";

    for (let i = 0; i < employees.length; i++) {
        let name = getTagValue(employees[i], "name");
        let role = getTagValue(employees[i], "role");
        let salary = getTagValue(employees[i], "salary");

        htmlOutput += `
            <div class="employee">
                <strong>Name:</strong> ${name} <br>
                <strong>Role:</strong> ${role} <br>
                <strong>Salary:</strong> ${salary}
            </div>
        `;
    }

    document.getElementById("output").innerHTML = htmlOutput;
}