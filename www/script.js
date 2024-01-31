document.getElementById('say-hello-button').addEventListener('click', function () {
    fetch('/say-hello')
        .then(response => response.text())
        .then(message => alert(message))
        .catch(error => console.error('Error:', error));
});