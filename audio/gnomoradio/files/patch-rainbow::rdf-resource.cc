--- rainbow/rdf-resource.cc.orig	Wed Dec 22 11:07:54 2004
+++ rainbow/rdf-resource.cc	Wed Dec 22 11:09:33 2004
@@ -35,7 +35,7 @@
 		resource = ref_ptr<RdfResource>(p->second);
 		if (resource->downloaded) { // already downloaded
 			map<Glib::ustring,xmlpp::Element*>::iterator el = resource->id_map.find(id);
-			signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
+			sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
 			sig.connect(slot);
 			sig(el != resource->id_map.end() ? el->second : 0, resource);
 			return;
@@ -47,7 +47,7 @@
 		Glib::ustring host, file;
 		unsigned short port;
 		if (!HttpClient::parse_url(uri, host, port, file)) {
-			signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
+			sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
 			sig.connect(slot);
 			sig(0, resource);
 			return;
@@ -55,14 +55,14 @@
 	}
 
 	// connect mem_fun to appropriate signal
-	map<Glib::ustring,signal<void,xmlpp::Element*, ref_ptr<RdfResource> >*>::iterator sig;
+	map<Glib::ustring,sigc::signal<void,xmlpp::Element*, ref_ptr<RdfResource> >*>::iterator sig;
 	sig = resource->signal_map.find(id);
 	if (sig != resource->signal_map.end()) {
 		// found existing signal for id
 		sig->second->connect(slot);
 	} else {
 		// need to create new signal to handle id
-		signal<void,xmlpp::Element*,ref_ptr<RdfResource> > *signal_ = new signal<void,xmlpp::Element*,ref_ptr<RdfResource> >;
+		sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> > *signal_ = new sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> >;
 		signal_->connect(slot);
 		resource->signal_map.insert(make_pair(id, signal_));
 	}
@@ -190,7 +190,7 @@
 
  error:
 	// call all signals
-	map<Glib::ustring,signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
+	map<Glib::ustring,sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
 	for (signal = signal_map.begin(); signal != signal_map.end(); ++signal) {
 		map<Glib::ustring,xmlpp::Element*>::iterator el = id_map.find(signal->first);
 		signal->second->emit(el != id_map.end() ? el->second : 0, ref_ptr<RdfResource>(this));
@@ -204,7 +204,7 @@
 
 void Rainbow::RdfResource::clear_signal_map ()
 {
-	map<Glib::ustring,signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
+	map<Glib::ustring,sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
 	for (signal = signal_map.begin(); signal != signal_map.end(); ++signal)
 		delete signal->second;
 	signal_map.clear();
