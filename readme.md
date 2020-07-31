# Objective

To have an authentication daemon where:

- each session has a uuid/key pair for identity purposes
- cookies or headers may be used to transmit the uuid/key pair to support browsers and desktop clients
- QR codes can be used to transfer a session between devices
- built-in dynamic permission scopes are provided via [baita](https://github.com/dsosd/baita)
- ephemeral accounts can be created for use in untrusted environments
- OAuth identity providers, e.g. Google sign-in, are supported
- a HashiCorp vault is used to maintain session info
