/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

var thrift = require('thrift');
var Calculator = require('../../gen-nodejs/Calculator');
var ttypes = require('../../gen-nodejs/tutorial_types');
const assert = require('assert');

var transport = thrift.TBufferedTransport;
var protocol = thrift.TBinaryProtocol;

var connection = thrift.createConnection("localhost", 9090, {
	transport : transport,
	protocol : protocol
});

connection.on('error', function(err) { assert(false, err); });

// Create a Calculator client with the connection
var client = thrift.createClient(Calculator, connection);
client.ping(function(err, response) { console.log('ping()'); });
client.add(1,1, function(err, response) { console.log("1+1=" + response); });
