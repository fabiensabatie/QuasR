/**
 * @Author: Fabien Sabatié <fabiensabatie>
 * @Date:   2018-07-07T23:39:07+02:00
 * @Email:  fsabatie@student.42.fr
 * @Project: PeachMe
 * @Last modified by:
 * @Last modified time: 2018-08-05T20:33:12+02:00
 */

global.__PREFIX				= 'qr_';
global.__BASEDIR			= __dirname;
global.__ROOT_URL			= 'http://localhost:8080';

// MongoDB info globals
// global.__MONGO_URL				= 'mongodb://sherpas:9aBuZqyTYkoJZezcwAwczcrR@ds161751.mlab.com:61751/tck_db';
global.__MONGO_URL					= 'mongodb://localhost:27017/';
global.__MONGO_DBNAME				= 'QuasR_db';
global.__MONGO_USERSCOLLECTION		= 'users';
global.__MONGO_APICOLLECTION		= 'apis';
global.__MONGO_APISTATESCOLLECTION	= 'states';
global.__MONGO_SERVICECOLLECTION	= 'services';
global.__MONGO_ENDPOINTCOLLECTION	= 'endpoints';

// Views info globals
global.__VIEWSPATH = 'dev/';
global.__DASH_PAGE = __PREFIX + 'dashboard';
global.__HOME_PAGE = __PREFIX + 'home';
global.__LOGIN_PAGE = __PREFIX + 'login';

// Controllers constants (avoiding double inclusion)
global.__CONTROLLERS_JS = false;
global.__PARSER_CONTROLLERS_JS = false;
