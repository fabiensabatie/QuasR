#include <stdio.h>
#include <glib-object.h>

#include <thrift/c_glib/protocol/thrift_binary_protocol.h>
#include <thrift/c_glib/transport/thrift_buffered_transport.h>
#include <thrift/c_glib/transport/thrift_socket.h>

// #include "gen-c_glib/calculator.h"

int main (void)
{
	ThriftSocket *socket;
	ThriftTransport *transport;
	ThriftProtocol *protocol;
	// CalculatorIf *client;

	GError *error = NULL;
	// InvalidOperation *invalid_operation = NULL;

	// Work *work;

	gint32 sum;
	gint32 diff;

	int exit_status = 0;

#if (!GLIB_CHECK_VERSION (2, 36, 0))
	g_type_init ();
#endif

	socket	  = g_object_new (THRIFT_TYPE_SOCKET, "hostname", "localhost", "port", 9090, NULL);
	transport = g_object_new (THRIFT_TYPE_BUFFERED_TRANSPORT, "transport", socket, NULL);
	protocol  = g_object_new (THRIFT_TYPE_BINARY_PROTOCOL, "transport", transport, NULL);

	thrift_transport_open (transport, &error);

	/* In the C (GLib) implementation of Thrift, service methods on the
	server are accessed via a generated client class that implements
	the service interface. In this tutorial, we access a Calculator
	service through an instance of CalculatorClient, which implements
	CalculatorIf. */

	// client = g_object_new (TYPE_CALCULATOR_CLIENT, "input_protocol",  protocol, "output_protocol", protocol, NULL);

	/* Each of the client methods requires at least two parameters: A
	pointer to the client-interface implementation (the client
	object), and a handle to a GError structure to receive
	information about any error that occurs.

	On success, client methods return TRUE. A return value of FALSE
	indicates an error occurred and the error parameter has been
	set. */

	// if (!error && calculator_if_ping (client, &error)) { puts ("ping()"); }

	/* Service methods that return a value do so by passing the result
	back via an output parameter (here, "sum"). */
	// if (!error && calculator_if_add (client, &sum, 1, 1, &error)) { printf ("1+1=%d\n", sum); }

	/* Thrift structs are implemented as GObjects, with each of the
	struct's members exposed as an object property. */

	if (error) {
		printf ("ERROR: %s\n", error->message);
		g_clear_error (&error);
		exit_status = 1;
	}

	thrift_transport_close (transport, NULL);

	// g_object_unref (client);
	g_object_unref (protocol);
	g_object_unref (transport);
	g_object_unref (socket);
	return exit_status;
}
